import { Component, OnInit, Input } from '@angular/core';

@Component({
  selector: 'app-section-selector',
  templateUrl: './section-selector.component.html',
  styleUrls: ['./section-selector.component.css']
})
export class SectionSelectorComponent implements OnInit {
  @Input() course: String;
  @Input() section: String;
  @Input() sections: String[];

  constructor() { }

  ngOnInit() {
    // console.log(`ngInit: ${this.section}`);
  }
  selectSection(selectedSection: String) {
    this.section = selectedSection;
  }
  ngOnChanges() {
    // console.log(`ngOnChanges: ${this.section}`);
    this.section = [
    {title: 'Assignments', url: `/courses/${this.course} + '/' + ${this.section}/assignments`},
    {title: 'Quizzes', url: `/courses/${this.course} + '/' + ${this.section}/quizzes`}
    ];
  }
}
