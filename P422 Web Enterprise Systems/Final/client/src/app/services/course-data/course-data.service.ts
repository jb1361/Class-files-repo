import { Injectable } from '@angular/core';
import {HttpClient} from '@angular/common/http';
import {UtilityService} from '../utility/utility.service';
import {Course} from '../../models/Course';

@Injectable({
  providedIn: 'root'
})
export class CourseDataService {

  constructor(private http: HttpClient, private utility: UtilityService) { }
  getCourses() {
    return this.http.get<Course[]>(this.utility.getRootURL() + '/v1/courses').toPromise();
  }
}
