import { Component, OnInit, Input } from '@angular/core';
import {Router} from '@angular/router';

@Component({
  selector: 'app-section-selector',
  templateUrl: './section-selector.component.html',
  styleUrls: ['./section-selector.component.css']
})
export class SectionSelectorComponent implements OnInit {
  @Input() course: String;
  @Input() sections: String[];
  sectionSelected: string;

  constructor(private router: Router) { }

  ngOnInit() {
    // console.log(`ngInit: ${this.section}`);
  }
  selectSection(selectedSection: string) {
    this.sectionSelected = selectedSection;
  }
  gotoAssignments(section) {
    this.router.navigateByUrl('/courses/' + this.course + '/' + this.sectionSelected + '/assignments');
  }
  gotoQuizes(section) {
    this.router.navigateByUrl('/courses/' + this.course + '/' + this.sectionSelected + '/quizes');
  }
}
