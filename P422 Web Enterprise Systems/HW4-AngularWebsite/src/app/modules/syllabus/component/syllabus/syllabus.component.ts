import {Component, OnInit} from '@angular/core';
import {Courses} from '../../../../data';

@Component({
  selector: 'app-syllabus',
  templateUrl: './syllabus.component.html',
  styleUrls: ['./syllabus.component.scss']
})
export class SyllabusComponent implements OnInit {
  selectedCourse: string;
  courseNames: string[];
  constructor(private courses: Courses) {
    this.selectedCourse = '';
    this.courseNames = courses.courseNames;
  }

  ngOnInit() {
  }

  // use the event emmiter here and bind it to syllabus info to update course info on that component.adsfdrsgdertgrtyrtyrt6yrty6rt4
  public changeCourse(course: string) {
    this.selectedCourse = course;
  }

}
