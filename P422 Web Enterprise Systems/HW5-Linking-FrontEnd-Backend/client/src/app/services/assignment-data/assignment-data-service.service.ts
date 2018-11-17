import { Injectable } from '@angular/core';
import {HttpClient} from '@angular/common/http';
import {Assignment} from '../../models/Assignment';
import {UtilityService} from '../utility/utility.service';

@Injectable({
  providedIn: 'root'
})
export class AssignmentDataServiceService {

  constructor(private http: HttpClient, private utility: UtilityService) { }
  getAssignments() {
    return this.http.get<Assignment[]>(this.utility.getRootURL() + '/v1/assignments').toPromise();
  }
  addAssignment(assignment: Assignment) {
    return this.http.post(this.utility.getRootURL() + '/v1/assignments', assignment);
  }
  getAssignment(name: String) {
    return this.http.get<Assignment>(this.utility.getRootURL() + '/v1/assignments/name');
  }
  updateAssignment(name: String, assignment: Assignment) {
    return this.http.put(this.utility.getRootURL() + '/v1/assignments/name', assignment);
  }
  getAssignmentGrade(name: String) {
    return this.http.get(this.utility.getRootURL() + '/v1/assignments/name/grades');
  }
  addAssignmentGrade(name: String, grade: number) {
    return this.http.post(this.utility.getRootURL() + '/v1/assignments/name/grades', grade);
  }
}
