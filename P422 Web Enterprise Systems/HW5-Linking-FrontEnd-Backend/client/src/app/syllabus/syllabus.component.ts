import { Component, OnInit } from '@angular/core';

import { SyllabusDataService } from '../models/syllabus-data.service';
import { Course } from '../models/Course';

import { ActivatedRoute, ParamMap } from '@angular/router';
import { Observable } from 'rxjs';
import { switchMap } from 'rxjs/operators';

@Component({
  selector: 'app-syllabus',
  templateUrl: './syllabus.component.html',
  styleUrls: ['./syllabus.component.css']
})
export class SyllabusComponent implements OnInit {
  selectedCourse: Observable<Course>;

  constructor(
  private route: ActivatedRoute,
  private syllabusDataService: SyllabusDataService
  ) { }

  ngOnInit() {
    // This code gets the :section parameter out of the route
    this.selectedCourse = this.route.paramMap.pipe(
    switchMap((params: ParamMap) => this.syllabusDataService.getCourse(params.get('section')))
    );
  }
}
