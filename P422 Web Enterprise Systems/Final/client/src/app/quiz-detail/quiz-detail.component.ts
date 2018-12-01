import { Component, OnInit } from '@angular/core';
import { Observable, of } from 'rxjs';
import {ActivatedRoute, ParamMap, Router} from '@angular/router';
import {switchMap} from 'rxjs/operators';
import {AssignmentDataServiceService} from '../services/assignment-data/assignment-data-service.service';
import {FormBuilder, FormGroup, Validators} from '@angular/forms';

@Component({
  selector: 'app-assignment-detail',
  templateUrl: './quiz-detail.component.html',
  styleUrls: ['./quiz-detail.component.css']
})
export class QuizDetailComponent implements OnInit {
  courseSection: string;
  courseTitle: string;
  quizName: Observable<String>;
  sectionName: Observable<String>;
  assForm: FormGroup;
  submitted = false;
  postSuccess = false;
  error = false;
  errorReason = '';
  constructor(
  private route: ActivatedRoute,
  private assDataService: AssignmentDataServiceService,
  private formBuilder: FormBuilder,
  private router: Router
  ) { }

  ngOnInit() {
    this.courseSection = this.route.snapshot.paramMap.get('section');
    this.courseTitle = this.route.snapshot.paramMap.get('course');
    this.quizName = this.route.paramMap.pipe(
    switchMap((params: ParamMap) => of(params.get('name')))
    );
    this.sectionName = this.route.paramMap.pipe(
    switchMap((params: ParamMap) => of(params.get('section')))
    );
    this.assForm = this.formBuilder.group({
      assName: ['', Validators.required],
      secName: ['', Validators.required],
      name: ['', Validators.required],
      textArea: ['', Validators.required],
    });
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
      'assignment': {
        'name': this.f.assName.value,
        'section': this.f.secName.value,
        'submitter': this.f.name.value,
      },
      'text': this.f.textArea.value
    };
    this.assDataService.addSubmission(data).catch((err) => {
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
  goBack() {
    this.router.navigateByUrl('/courses/' + this. courseTitle + '/' + this.courseSection + '/assignments');
  }
}
