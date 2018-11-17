import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, ParamMap } from '@angular/router';
import { Observable, of } from 'rxjs';
import { switchMap } from 'rxjs/operators';
import {Assignment} from '../models/Assignment';
import {AssignmentDataServiceService} from '../services/assignment-data/assignment-data-service.service';

@Component({
  selector: 'app-assignment',
  templateUrl: './assignment.component.html',
  styleUrls: ['./assignment.component.css']
})
export class AssignmentComponent implements OnInit {
  section: Observable<String>;
  assignments: Assignment[];
  constructor(
    private route: ActivatedRoute,
    private assignmentDataService: AssignmentDataServiceService
  ) { }

  ngOnInit() {
    // This code gets the :section parameter out of the route
    this.section = this.route.paramMap.pipe(
    switchMap((params: ParamMap) => of(params.get('section')))
    );
    this.getAssignments();
  }
  getAssignments() {
    this.assignmentDataService.getAssignments().then((res) => {
      this.assignments = res;
    });
  }

}
