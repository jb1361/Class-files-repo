import {Component, Input, OnInit} from '@angular/core';
import {CourseData} from '../../../../data';

@Component({
  selector: 'app-syllabus-info',
  templateUrl: './syllabus-info.component.html',
  styleUrls: ['./syllabus-info.component.scss']
})
export class SyllabusInfoComponent implements OnInit {
  @Input() courseName: string;
  title: string;
  sectionNumber: string;
  description: string;
  information: string;
  times: Date;
  scale: string;

  constructor(private info: CourseData) {
    this.title = info.title;
  }

  ngOnInit() {
  }
  public getCourse(course) {
    console.log(course);
  }

}
