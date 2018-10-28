import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { UniversityInfoComponent } from './university-info.component';

describe('UniversityInfoComponent', () => {
  let component: UniversityInfoComponent;
  let fixture: ComponentFixture<UniversityInfoComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ UniversityInfoComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(UniversityInfoComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
