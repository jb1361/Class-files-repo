import { Component, OnInit } from '@angular/core';
import { Observable, of } from 'rxjs';
import { ActivatedRoute, ParamMap } from '@angular/router';
import {catchError, switchMap} from 'rxjs/operators';
import {AssignmentDataServiceService} from '../services/assignment-data/assignment-data-service.service';
import {Submission} from '../models/Submission';
import {FormBuilder, FormControl, FormGroup, Validators} from '@angular/forms';

@Component({
  selector: 'app-assignment-detail',
  templateUrl: './assignment-detail.component.html',
  styleUrls: ['./assignment-detail.component.css']
})
export class AssignmentDetailComponent implements OnInit {
  assignmentName: Observable<String>;
  sectionName: Observable<String>;
  assForm: FormGroup;
  submitted = false;
  postSuccess = false;
  error = false;
  errorReason = '';
  constructor(
  private route: ActivatedRoute,
  private assDataService: AssignmentDataServiceService,
  private formBuilder: FormBuilder
  ) { }

  ngOnInit() {
    this.assignmentName = this.route.paramMap.pipe(
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
     const submission = data;
     this.assDataService.addSubmission(submission).catch((err) => {
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
}
