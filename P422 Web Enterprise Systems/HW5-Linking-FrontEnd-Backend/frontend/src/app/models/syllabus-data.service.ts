import { Injectable } from '@angular/core';
import { Course } from './Course';
import { HttpClient }    from '@angular/common/http';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class SyllabusDataService {

  constructor(private http: HttpClient) { }

	url = '/v1/courses';
	getCourses(): Observable<Course[]> {
		return this.http.get<Course[]>(this.url);
	}

	getCourse(section: String): Observable<Course> {
		return this.http.get<Course>(`${this.url}/${section}`);
	}
}
