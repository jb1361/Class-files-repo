import { Component, OnInit } from '@angular/core';
import {ActivatedRoute, Router} from '@angular/router';
import {FormBuilder, FormGroup, Validators} from '@angular/forms';
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
  quizQuestions: Array;
  assForm: FormGroup;
  loading = true;
  submitted = false;
  postSuccess = false;
  error = false;
  errorReason = '';
  constructor(
  private route: ActivatedRoute,
  private assDataService: QuizDataServiceService,
  private formBuilder: FormBuilder,
  private router: Router
  ) { }

  ngOnInit() {
    this.courseSection = this.route.snapshot.paramMap.get('section');
    this.courseTitle = this.route.snapshot.paramMap.get('course');
    this.quizName = this.route.snapshot.paramMap.get('name');
    this.assForm = this.formBuilder.group({
      assName: ['', Validators.required],
      secName: ['', Validators.required],
      questions: ['', Validators.required],
    });
    this.getQuestions();
  }
  get f() { return this.assForm.controls; }
  onSubmit() {
    this.error = false;
    this.postSuccess = false;
    this.submitted = true;
    if (this.assForm.invalid) {
      return;
    }
    const data = {
      'name': this.f.assName.value,
      'section': this.f.secName.value,
      'grade': this.calculateGrade(),
    };
    this.assDataService.addQuizSubmission(data).catch((err) => {
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
    return 100;
  }
  goBack() {
    this.router.navigateByUrl('/courses/' + this. courseTitle + '/' + this.courseSection + '/quizes');
  }
  getQuestions() {
    this.assDataService.getQuizByQuizName(this.quizName).then((res) => {
      const questions = [];
      res[0].questions.forEach( (val) => {
        questions.push(val);
      });
      console.log(questions);
      this.quizQuestions = questions;
      this.loading = false;
    });
  }
}
