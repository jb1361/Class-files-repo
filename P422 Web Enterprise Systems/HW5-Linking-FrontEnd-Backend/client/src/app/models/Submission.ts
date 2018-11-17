import {Assignment} from './Assignment';
import {Buffer} from 'buffer';

export class Submission {
  assignment: {};
  fileName?: String;
  upload?: Buffer;
  text: String;
  submissionDate?: number;
  grade?: String;
}
