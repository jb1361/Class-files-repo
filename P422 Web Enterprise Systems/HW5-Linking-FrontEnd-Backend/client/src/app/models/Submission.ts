import {Assignment} from './Assignment';

export class Submission {
  assignment: Assignment;
  fileName: String;
  upload: Buffer;
  text: String;
  submissionDate: number;
  grade: String;
}
