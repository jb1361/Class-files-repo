import { Component, OnInit } from '@angular/core';

import { SyllabusDataService } from '../models/syllabus-data.service';
import { Course } from '../models/Course';

import { Router, RoutesRecognized } from '@angular/router';
import { Observable, of } from 'rxjs';
import { switchMap } from 'rxjs/operators';

@Component({
  selector: 'app-course-selection',
  templateUrl: './course-selection.component.html',
  styleUrls: ['./course-selection.component.css']
})
export class CourseSelectionComponent implements OnInit {
  courses: Observable<Course[]>;
  courseSection: Observable<String>;

  constructor(
    private router: Router,
    private syllabusDataService: SyllabusDataService
    ) { }

  ngOnInit() {
    this.courses = this.syllabusDataService.getCourses();

  this.router.events.subscribe(routerEvent => {
      if (routerEvent instanceof RoutesRecognized) {
        const section = routerEvent.state.root['_routerState']['_root'].children[0].value.params.section;
        this.courseSection = of(section);
      }
    });
  }
}
