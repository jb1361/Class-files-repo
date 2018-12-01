import { Injectable } from '@angular/core';
import {HttpClient} from '@angular/common/http';
import {Assignment} from '../../models/Assignment';
import {UtilityService} from '../utility/utility.service';
import {Submission} from '../../models/Submission';

@Injectable({
  providedIn: 'root'
})
export class AssignmentDataServiceService {

  constructor(private http: HttpClient, private utility: UtilityService) { }

  getAssignmentsBySection(section: string) {
    return this.http.get<Assignment[]>(this.utility.getRootURL() + '/v1/assignments/get-by-section/' + section).toPromise();
  }

  addSubmission(submission: Submission) {
    return this.http.post(this.utility.getRootURL() + '/v1/submissions', submission).toPromise();
  }
}
