import { TestBed } from '@angular/core/testing';

import { AssignmentDataServiceService } from './assignment-data-service.service';

describe('AssignmentDataServiceService', () => {
  beforeEach(() => TestBed.configureTestingModule({}));

  it('should be created', () => {
    const service: AssignmentDataServiceService = TestBed.get(AssignmentDataServiceService);
    expect(service).toBeTruthy();
  });
});
