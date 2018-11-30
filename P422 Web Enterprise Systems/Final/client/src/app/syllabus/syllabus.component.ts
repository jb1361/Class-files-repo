import { Component, OnInit } from '@angular/core';
import {Course} from '../models/Course';
import {ActivatedRoute, ParamMap, Router} from '@angular/router';
import {CourseDataService} from '../services/course-data/course-data.service';

@Component({
  selector: 'app-syllabus',
  templateUrl: './syllabus.component.html',
  styleUrls: ['./syllabus.component.css']
})
export class SyllabusComponent implements OnInit {
  courseTitle: String;
  selectedCourse: Course;
  courseSections: String[] = [];
  constructor(
    private router: Router,
    private route: ActivatedRoute,
    private courseDataService: CourseDataService) {
  }

  ngOnInit() {
    this.courseTitle = this.route.snapshot.paramMap.get('course');
    this.courseDataService.getCourse(this.courseTitle).then( (res) => {
      this.selectedCourse = res;
    });
    this.courseDataService.getCourseSections(this.courseTitle).then( (res) => {
      res.forEach((val) => {
        if (this.courseSections.indexOf(val.section)) {
          this.courseSections.push(val.section);
        }
      });
    });
  }
}
