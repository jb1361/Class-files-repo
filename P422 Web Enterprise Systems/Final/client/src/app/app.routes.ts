import {Routes} from '@angular/router';
import {HomepageComponent} from './homepage/homepage.component';
import {SyllabusComponent} from './syllabus/syllabus.component';
import {AssignmentComponent} from './assignment/assignment.component';
import {AssignmentDetailComponent} from './assignment-detail/assignment-detail.component';
import {PageNotFoundComponent} from './page-not-found/page-not-found.component';
import {QuizComponent} from './quiz/quiz.component';

export const ROUTES: Routes = [
  { path: '', component: HomepageComponent },
  { path: 'courses/:course/syllabus', component: SyllabusComponent },
  { path: 'courses/:course/:section/assignments', component: AssignmentComponent },
  { path: 'courses/:course/:section/assignments/:name', component: AssignmentDetailComponent },
  { path: 'courses/:course/:section/quizes', component: QuizComponent },
  { path: '**', component: PageNotFoundComponent }
];
