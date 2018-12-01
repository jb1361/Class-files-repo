export class Quiz {
  name: String;
  section: String;
  questions: {
    question: String,
    options: String[],
    answer: Number
  };
}
