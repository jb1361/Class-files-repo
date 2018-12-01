import { Injectable } from '@angular/core';
import {HttpClient} from '@angular/common/http';
import {UtilityService} from '../utility/utility.service';
import {Quiz} from '../../models/Quiz';
import {QuizSubmission} from '../../models/QuizSubmission';

@Injectable({
  providedIn: 'root'
})
export class QuizDataServiceService {

  constructor(private http: HttpClient, private utility: UtilityService) { }
  getQuizesBySection(section: string) {
    return this.http.get<Quiz[]>(this.utility.getRootURL() + '/v1/quizes/get-by-section/' + section).toPromise();
  }
  addQuizSubmission(submission: QuizSubmission) {
    return this.http.post(this.utility.getRootURL() + '/v1/quizSubmissions', submission).toPromise();
  }
}
