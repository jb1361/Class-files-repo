import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { HttpClientModule } from '@angular/common/http';
import { NgbModule } from '@ng-bootstrap/ng-bootstrap';
import {FormsModule, ReactiveFormsModule} from '@angular/forms';
import {RouterModule} from '@angular/router';
import {ROUTES} from './app.routes';

import { AppComponent } from './app.component';
import { SyllabusComponent } from './syllabus/syllabus.component';
import { AssignmentComponent } from './assignment/assignment.component';
import { PageNotFoundComponent } from './page-not-found/page-not-found.component';
import { AssignmentDetailComponent } from './assignment-detail/assignment-detail.component';
import { CourseSelectionComponent } from './course-selection/course-selection.component';
import { SectionSelectorComponent } from './section-selector/section-selector.component';
import { HomepageComponent } from './homepage/homepage.component';
import {QuizComponent} from './quiz/quiz.component';
import {QuizDetailComponent} from './quiz-detail/quiz-detail.component';

@NgModule({
  declarations: [
    AppComponent,
    SyllabusComponent,
    AssignmentComponent,
    PageNotFoundComponent,
    AssignmentDetailComponent,
    CourseSelectionComponent,
    SectionSelectorComponent,
    HomepageComponent,
    QuizComponent,
    QuizDetailComponent
  ],
  imports: [
    BrowserModule,
    HttpClientModule,
    NgbModule,
    FormsModule,
    ReactiveFormsModule,
    RouterModule.forRoot(ROUTES),
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
