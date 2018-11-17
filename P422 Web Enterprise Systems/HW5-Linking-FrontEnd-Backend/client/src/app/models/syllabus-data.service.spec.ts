import { TestBed } from '@angular/core/testing';

import { SyllabusDataService } from './syllabus-data.service';

describe('SyllabusDataService', () => {
  beforeEach(() => TestBed.configureTestingModule({}));

  it('should be created', () => {
    const service: SyllabusDataService = TestBed.get(SyllabusDataService);
    expect(service).toBeTruthy();
  });
});
