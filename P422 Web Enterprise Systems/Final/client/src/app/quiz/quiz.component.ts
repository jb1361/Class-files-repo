import { Component, OnInit } from '@angular/core';
import {ActivatedRoute, Router} from '@angular/router';
import {QuizDataServiceService} from '../services/quiz-data/quiz-data-service.service';
import {Quiz} from '../models/Quiz';

@Component({
  selector: 'app-quiz',
  templateUrl: './quiz.component.html',
  styleUrls: ['./quiz.component.css']
})
export class QuizComponent implements OnInit {
  quizes: Quiz[];
  courseSection: string;
  courseTitle: string;
  constructor(
    private route: ActivatedRoute,
    private quizDataService: QuizDataServiceService,
    private router: Router
  ) { }

  ngOnInit() {
    // This code gets the :section parameter out of the route
    this.courseSection = this.route.snapshot.paramMap.get('section');
    this.courseTitle = this.route.snapshot.paramMap.get('course');
    this.getQuizes();
  }
  getQuizes() {
    this.quizDataService.getQuizesBySection(this.courseSection).then((res) => {
      this.quizes = res;
    });
  }
  gotoSyllabus() {
    this.router.navigateByUrl('/courses/' + this.courseTitle + '/syllabus');
  }

}
