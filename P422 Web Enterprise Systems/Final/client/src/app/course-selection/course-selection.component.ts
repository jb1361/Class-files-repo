import { Component, OnInit } from '@angular/core';

import { Course } from '../models/Course';
import {CourseDataService} from '../services/course-data/course-data.service';
import {forEach} from '@angular/router/src/utils/collection';

@Component({
  selector: 'app-course-selection',
  templateUrl: './course-selection.component.html',
  styleUrls: ['./course-selection.component.css']
})
export class CourseSelectionComponent implements OnInit {
  courses: Course[];
  courseTitles: String[] = [];
  courseSection: String;
  loading: boolean;
  constructor(
    private courseDataService: CourseDataService,
    ) { }

  ngOnInit() {
    this.loading = true;
    this.getCourses();
  }
  getCourses() {
    this.courseDataService.getCourses().then((res) => {
      this.courses = res;
      this.filterCourses();
    });
  }
  filterCourses() {
    this.courses.forEach((val) => {
      if (this.courseTitles.indexOf(val.title)) {
        this.courseTitles.push(val.title);
      }
    });
    console.log(this.courseTitles);
    this.loading = false;
  }
}
