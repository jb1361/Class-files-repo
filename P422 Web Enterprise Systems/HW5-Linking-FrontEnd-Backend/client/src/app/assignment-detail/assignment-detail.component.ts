import { Component, OnInit } from '@angular/core';
import { Observable, of } from 'rxjs';
import { ActivatedRoute, ParamMap } from '@angular/router';
import { switchMap } from 'rxjs/operators';

@Component({
  selector: 'app-assignment-detail',
  templateUrl: './assignment-detail.component.html',
  styleUrls: ['./assignment-detail.component.css']
})
export class AssignmentDetailComponent implements OnInit {
 assignmentName: Observable<String>;
 sectionName: Observable<String>;

  constructor(
  private route: ActivatedRoute,
  ) { }

  ngOnInit() {
    this.assignmentName = this.route.paramMap.pipe(
    switchMap((params: ParamMap) => of(params.get('name')))
    );
    this.sectionName = this.route.paramMap.pipe(
    switchMap((params: ParamMap) => of(params.get('section')))
    );
  }

}
