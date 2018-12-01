import { Injectable } from '@angular/core';
import {HttpClient} from '@angular/common/http';
import {UtilityService} from '../utility/utility.service';
import {Quiz} from '../../models/Quiz';

@Injectable({
  providedIn: 'root'
})
export class QuizDataServiceService {

  constructor(private http: HttpClient, private utility: UtilityService) { }
  getQuizes() {
    return this.http.get<Quiz[]>(this.utility.getRootURL() + '/v1/quizes').toPromise();
  }
  getQuizesBySection(section: string) {
    return this.http.get<Quiz[]>(this.utility.getRootURL() + '/v1/quizes/get-by-section/' + section).toPromise();
  }

}
