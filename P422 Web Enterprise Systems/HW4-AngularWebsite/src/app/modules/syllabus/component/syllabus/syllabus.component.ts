import {Component, EventEmitter, OnInit, Output} from '@angular/core';
import {Courses} from '../../../../data';

@Component({
  selector: 'app-syllabus',
  templateUrl: './syllabus.component.html',
  styleUrls: ['./syllabus.component.scss']
})
export class SyllabusComponent implements OnInit {
  selectedCourse: string;
  courseNames: string[];
  @Output() courseChanged: EventEmitter<any> = new EventEmitter<any>();
  constructor(private courses: Courses) {
    this.selectedCourse = '';
    this.courseNames = courses.courseNames;
  }

  ngOnInit() {
  }

  public changeCourse(course: string) {
    this.selectedCourse = course;
  }

}
