import {Component, Input, OnInit, OnChanges} from '@angular/core';
import {Calendar} from '../../../../data';

@Component({
  selector: 'app-calendar',
  templateUrl: './calendar.component.html',
  styleUrls: ['./calendar.component.scss']
})
export class CalendarComponent implements OnInit, OnChanges {
  @Input() courseName: string;
  calendar = new Calendar();
  data: any[];
  dates: any[] = [];

  constructor() { }

  ngOnInit() {
  }
  ngOnChanges() {
    this.dates = [];
    this.data = this.calendar.courseCalender[this.courseName];
    for (let key in this.data) {
      this.dates.push(this.data[key]);
    }
  }

}
