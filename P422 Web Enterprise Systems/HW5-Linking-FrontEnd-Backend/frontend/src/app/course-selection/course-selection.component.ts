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
		  // This is ugly, but I was able to reach deep into the router to find our section.
		  // The reason I'm doing this is that we are currently OUTSIDE of the router-outlet component so the ActiveRoute is not hooked up in this component
		  // I don't expect this to work outside of the current version of Angular
		  // BUG: Also note that this breaks down on PageNotFoundComponent since it doesn't have a parameter
		  let section = routerEvent.state.root['_routerState']['_root'].children[0].value.params.section;
		  this.courseSection = of(section);
      }
    });
  }
}
