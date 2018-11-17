import { Component, OnInit } from '@angular/core';
import { Observable, of } from 'rxjs';
import { ActivatedRoute, ParamMap } from '@angular/router';
import { switchMap } from 'rxjs/operators';
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
      console.log('invalid form');
      return;
    }
   // console.log(form.);
    // let submission = new Submission();
    // this.assDataService.addSubmission(submission);
  }
}
