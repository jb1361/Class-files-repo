import { Component, OnInit, Input } from '@angular/core';

@Component({
  selector: 'app-section-selector',
  templateUrl: './section-selector.component.html',
  styleUrls: ['./section-selector.component.css']
})
export class SectionSelectorComponent implements OnInit {
	@Input() section: String;
	sections: any;

  constructor() { }

  ngOnInit() {
	  console.log(`ngInit: ${this.section}`);
  }

  ngOnChanges() {
	  console.log(`ngOnChanges: ${this.section}`);
	  this.sections = [
		{title: "Syllabus", url: `/courses/${this.section}/syllabus`},
		{title: "Assignments", url: `/courses/${this.section}/assignments`},
		{title: "Quizzes", url: `/courses/${this.section}/quizzes`}
	  ]
  }
}
