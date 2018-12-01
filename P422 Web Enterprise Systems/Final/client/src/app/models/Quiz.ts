export class Quiz {
  name: String;
  section: String;
  questions: {
    question: {
      questionName: String,
      options: {
        option0: String,
        option1: String,
        option2: String,
        option3: String
      },
      answer: Number
    }
  };
}
