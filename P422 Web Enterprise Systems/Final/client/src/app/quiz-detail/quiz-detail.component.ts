import { Component, OnInit } from '@angular/core';
import {ActivatedRoute, Router} from '@angular/router';
import {FormBuilder, FormControl, FormGroup, Validators} from '@angular/forms';
import {QuizDataServiceService} from '../services/quiz-data/quiz-data-service.service';

@Component({
  selector: 'app-quiz-detail',
  templateUrl: './quiz-detail.component.html',
  styleUrls: ['./quiz-detail.component.css']
})
export class QuizDetailComponent implements OnInit {
  courseSection: string;
  courseTitle: string;
  quizName: string;
  quizQuestions: any[];
  quizForm: FormGroup;
  loading = true;
  submitted = false;
  postSuccess = false;
  error = false;
  errorReason = '';
  graded = false;
  grade = 0;
  constructor(
    private route: ActivatedRoute,
    private quizDataService: QuizDataServiceService,
    private formBuilder: FormBuilder,
    private router: Router
  ) {
  }

  ngOnInit() {
    this.courseSection = this.route.snapshot.paramMap.get('section');
    this.courseTitle = this.route.snapshot.paramMap.get('course');
    this.quizName = this.route.snapshot.paramMap.get('name');
    this.getQuestions();
  }

  get f() {
    return this.quizForm.controls;
  }

  onSubmit() {
    this.error = false;
    this.postSuccess = false;
    this.submitted = true;
    if (this.quizForm.invalid) {
      return;
    }
    const data = {
      'name': this.f.quizName.value,
      'section': this.f.secName.value,
      'grade': this.calculateGrade(),
    };
    this.graded = true;
    this.quizDataService.addQuizSubmission(data).catch((err) => {
      if (err) {
        this.error = true;
        this.errorReason = err.message;
      }
    }).then((res) => {
      if (res) {
        this.postSuccess = true;
      }
    });
  }

  calculateGrade() {
    const givenQuestions = [];
    let correct = 0;
    this.quizQuestions.forEach(question => {
      givenQuestions.push([question.questionName, question.answer]);
    });
    givenQuestions.forEach( (name) => {
      if ((name[1]) === (+this.quizForm.get(name[0]).value + 1)) {
        correct++;
      }
    });
    this.grade = (correct / givenQuestions.length) * 100;
    return (correct / givenQuestions.length) * 100;
  }

  goBack() {
    this.router.navigateByUrl('/courses/' + this.courseTitle + '/' + this.courseSection + '/quizes');
  }
  getErrors(controlName: string) {
    if (this.quizForm.get(controlName).invalid) {
      return true;
    }
    return false;
  }
  getQuestions() {
    this.quizDataService.getQuizByQuizName(this.quizName).then((res) => {
      const questions = [];
      res[0].questions.forEach((val) => {
        questions.push(val);
      });
      this.quizQuestions = questions;
      this.createFormControls(questions);
      this.loading = false;
    });
  }
  // @ts-ignore: next line
  createFormControls(questions: Array) {
    this.quizForm = this.formBuilder.group({
      quizName: ['', Validators.required],
      secName: ['', Validators.required],
    });
    questions.forEach(question => {
      this.quizForm.addControl(question.questionName, new FormControl('', Validators.required));
    });
  }
}
