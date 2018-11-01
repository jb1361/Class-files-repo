
export class Courses {
  courseNames = ['P422', 'C343'];
}

export class CourseData {
  title: string;
  section: string;
  description: string;
  bookInfo: string;
  meetingTime: Date;
  gradingScale: string;
  calendar: Calendar[];
  universityInfo: string;
  constructor() {
    this.title = 'Test';
  }

}

export class Calendar {

}
