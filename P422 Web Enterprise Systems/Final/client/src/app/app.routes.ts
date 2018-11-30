import {Routes} from '@angular/router';
import {HomepageComponent} from './homepage/homepage.component';
import {SyllabusComponent} from './syllabus/syllabus.component';
import {AssignmentComponent} from './assignment/assignment.component';
import {AssignmentDetailComponent} from './assignment-detail/assignment-detail.component';
import {PageNotFoundComponent} from './page-not-found/page-not-found.component';

export const ROUTES: Routes = [
  { path: '', component: HomepageComponent },
  { path: 'courses/:course/syllabus', component: SyllabusComponent },
  // { path: 'courses/:course/assignments', component: AssignmentComponent },
  // { path: 'courses/:course/assignments/:name', component: AssignmentDetailComponent },
  // { path: 'courses/:course', redirectTo: 'courses/:section/syllabus' },
  { path: '**', component: PageNotFoundComponent }
];
