import {Component, Input, OnInit, OnChanges} from '@angular/core';
import {CourseData} from '../../../../data';

@Component({
  selector: 'app-syllabus-info',
  templateUrl: './syllabus-info.component.html',
  styleUrls: ['./syllabus-info.component.scss']
})
export class SyllabusInfoComponent implements OnInit, OnChanges {
  @Input() courseName: string;
  course = new CourseData();
  title: string;
  sectionNumber: string;
  description: string;
  information: string;
  times: string;
  scale: string;

  constructor() { }
  ngOnInit() { }
  ngOnChanges() {
    this.title = this.course.courseData[this.courseName].title;
    this.sectionNumber = this.course.courseData[this.courseName].section;
    this.description = this.course.courseData[this.courseName].description;
    this.information = this.course.courseData[this.courseName].bookInfo;
    this.times = this.course.courseData[this.courseName].meetingTime;
    this.scale = this.getGradingScale(this.course.courseData[this.courseName].gradingScale);
  }
  public getGradingScale(gradingScale) {
    let scale = '';
    for (let key in gradingScale) {
      scale += key + ': ' + gradingScale[key] + ' ';
      // Use `key` and `value`
    }
    return scale;
  }

}
