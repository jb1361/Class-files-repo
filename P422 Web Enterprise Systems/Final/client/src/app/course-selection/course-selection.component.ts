import { Component, OnInit } from '@angular/core';

import { Course } from '../models/Course';
import {CourseDataService} from '../services/course-data/course-data.service';
import {Router} from '@angular/router';

@Component({
  selector: 'app-course-selection',
  templateUrl: './course-selection.component.html',
  styleUrls: ['./course-selection.component.css']
})
export class CourseSelectionComponent implements OnInit {
  courses: Course[];
  courseTitles: String[] = [];
  loading: boolean;
  constructor(
    private router: Router,
    private courseDataService: CourseDataService,
    ) { }

  ngOnInit() {
    this.loading = true;
    this.getCourses();
  }
  selectCourse(course: string) {
    this.router.navigateByUrl('courses/' + course + '/syllabus');
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
        console.log(val.title);
        this.courseTitles.push(val.title);
      }
    });
    this.loading = false;
  }
}
