import { Component, OnInit } from '@angular/core';

import { Course } from '../models/Course';
import {CourseDataService} from '../services/course-data/course-data.service';

@Component({
  selector: 'app-course-selection',
  templateUrl: './course-selection.component.html',
  styleUrls: ['./course-selection.component.css']
})
export class CourseSelectionComponent implements OnInit {
  courses: Course[];
  courseSection: String;

  constructor(
    private courseDataService: CourseDataService,
    ) { }

  ngOnInit() {
    this.getCourses();
  }
  getCourses() {
    this.courseDataService.getCourses().then((res) => {
      this.courses = res;
    });
  }
}
