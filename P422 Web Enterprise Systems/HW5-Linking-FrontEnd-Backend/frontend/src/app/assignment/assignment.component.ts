import { Component, OnInit } from '@angular/core';

import { ActivatedRoute, ParamMap } from '@angular/router';
import { Observable, of } from 'rxjs';
import { switchMap } from 'rxjs/operators';

@Component({
  selector: 'app-assignment',
  templateUrl: './assignment.component.html',
  styleUrls: ['./assignment.component.css']
})
export class AssignmentComponent implements OnInit {
  section: Observable<String>;

  constructor(
	private route: ActivatedRoute,
  ) { }

  ngOnInit() {
	  // This code gets the :section parameter out of the route
	  this.section = this.route.paramMap.pipe(
		switchMap((params: ParamMap) => of(params.get('section')))
	  );
  }

}
