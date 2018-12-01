import { Component, OnInit } from '@angular/core';
import {ActivatedRoute, Router} from '@angular/router';

import {Assignment} from '../models/Assignment';
import {AssignmentDataServiceService} from '../services/assignment-data/assignment-data-service.service';

@Component({
  selector: 'app-assignment',
  templateUrl: './assignment.component.html',
  styleUrls: ['./assignment.component.css']
})
export class AssignmentComponent implements OnInit {
  assignments: Assignment[];
  courseSection: string;
  courseTitle: string;
  constructor(
    private route: ActivatedRoute,
    private assignmentDataService: AssignmentDataServiceService,
    private router: Router
  ) { }

  ngOnInit() {
    // This code gets the :section parameter out of the route
    this.courseSection = this.route.snapshot.paramMap.get('section');
    this.courseTitle = this.route.snapshot.paramMap.get('course');
    this.getAssignments();
  }
  getAssignments() {
    this.assignmentDataService.getAssignmentsBySection(this.courseSection).then((res) => {
      this.assignments = res;
    });
  }
  gotoSyllabus() {
    this.router.navigateByUrl('/courses/' + this. courseTitle + '/syllabus');
  }

}
