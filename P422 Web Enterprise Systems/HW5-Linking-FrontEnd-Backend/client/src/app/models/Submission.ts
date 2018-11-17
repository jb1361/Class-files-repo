import {Assignment} from './Assignment';
import {Buffer} from 'buffer';

export class Submission {
  assignment: Assignment;
  fileName: String;
  upload: Buffer;
  text: String;
  submissionDate: number;
  grade: String;
}
