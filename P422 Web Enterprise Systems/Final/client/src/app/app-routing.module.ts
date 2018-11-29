import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { SyllabusComponent } from './syllabus/syllabus.component';
import { AssignmentComponent } from './assignment/assignment.component';
import { AssignmentDetailComponent } from './assignment-detail/assignment-detail.component';
import { PageNotFoundComponent } from './page-not-found/page-not-found.component';
import { HomepageComponent } from './homepage/homepage.component';

const routes: Routes = [
  { path: '', component: HomepageComponent },
  { path: 'courses/:section/syllabus', component: SyllabusComponent },
  { path: 'courses/:section/assignments', component: AssignmentComponent },
  { path: 'courses/:section/assignments/:name', component: AssignmentDetailComponent },
  { path: 'courses/:section', redirectTo: 'courses/:section/syllabus' },
  { path: '**', component: PageNotFoundComponent }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
