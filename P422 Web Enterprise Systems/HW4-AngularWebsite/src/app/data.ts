
export class Courses {
  courseNames = ['P422', 'C343'];
}

export class CourseData {
  public courseData = {
   'P422': {
     title: 'Web Enterprize Systems',
     section: 'Course section here',
     description: 'Angular Rocks!',
     bookInfo: 'Don\'t get the book.',
     meetingTime: '7:30 PM TUTH',
     gradingScale: {'F':  '< 60', 'D': ' < 70', 'C': '< 80', 'B': '< 90', 'A': '> 90'},
     calender: new Calendar().courseCalender['P422']
   },
    'C343': {
      title: 'Data structures',
      section: 'Homework!',
      description: 'Homework Rocks!',
      bookInfo: 'Don\'t get the book.',
      meetingTime: '7:30 PM MOWE',
      gradingScale: {'F':  '< 60', 'D': ' < 70', 'C': '< 80', 'B': '< 90', 'A': '> 90'},
      calender: new Calendar().courseCalender['C343']
    }
  };
}

export class Calendar {

  public courseCalender = {
    'P422': {
      0: {
        date: '11-01-2018',
        description: 'Doing Angular',
        notes: 'a link here'
      },
      1: {
        date: '11-04-2018',
        description: 'Doing Angular again',
        notes: 'a link here again'
      }
    },
    'C343': {
      0: {
        date: '11-02-2018',
        description: 'Assigning Homework',
        notes: 'a link here'
      },
      1: {
        date: '11-05-2018',
        description: 'Assigning ghgomework on top of homework and assigning homework to some guy in the hallway.',
        notes: 'a link here again'
      }
    }
  };
}
