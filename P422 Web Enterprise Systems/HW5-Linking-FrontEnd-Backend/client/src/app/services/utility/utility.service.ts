import { Injectable } from '@angular/core';
import {environment} from '../../../environments/environment';

@Injectable({
  providedIn: 'root'
})
export class UtilityService {

  constructor() { }
  getRootURL() {
    return environment.host + ':' + environment.port;
  }
}
