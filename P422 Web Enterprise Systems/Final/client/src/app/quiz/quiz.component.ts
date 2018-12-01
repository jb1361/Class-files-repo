import { Component, OnInit } from '@angular/core';
import {ActivatedRoute, ParamMap, Router} from '@angular/router';
import { Observable, of } from 'rxjs';
import { switchMap } from 'rxjs/operators';
import {QuizDataServiceService} from '../services/quiz-data/quiz-data-service.service';
import {Quiz} from '../models/Quiz';

@Component({
  selector: 'app-assignment',
  templateUrl: './quiz.component.html',
  styleUrls: ['./quiz.component.css']
})
export class QuizComponent implements OnInit {
  section: Observable<String>;
  quizes: Quiz[];
  courseSection: string;
  courseTitle: string;
  constructor(
    private route: ActivatedRoute,
    private assignmentDataService: QuizDataServiceService,
    private router: Router
  ) { }

  ngOnInit() {
    // This code gets the :section parameter out of the route
    this.section = this.route.paramMap.pipe(
    switchMap((params: ParamMap) => of(params.get('section')))
    );
    this.courseSection = this.route.snapshot.paramMap.get('section');
    this.courseTitle = this.route.snapshot.paramMap.get('course');
    this.getQuizes();
  }
  getQuizes() {
    this.assignmentDataService.getQuizesBySection(this.courseSection).then((res) => {
      this.quizes = res;
    });
  }
  gotoSyllabus() {
    this.router.navigateByUrl('/courses/' + this. courseTitle + '/syllabus');
  }

}
