#pragma once

// Scroll Bar Wrapper
// Date: 10/16
// Author: Dr. Holly

class ScrollBar1
{
	//! is modeled by tuple
	//!          attached: Boolean
	//!          scrollTypeValue: Integer
	//!          currentPosition: Integer
	//!          scrollMinValue: Integer
	//!          scrollMaxValue: Integer
	//!          numLinesPerLineScroll: Integer
	//!          numLinesPerPageScroll: Integer
	//!          lineHeightInScreenUnits: Integer
	//!          windowHeightInScreenUnits: Integer
	//!   exemplar self
	//!   initialization
	//!     ensures:   self = (false, vScrollBar, 0, 0, 0, 1, 1, 1, 1)

public:
	enum {
		// Scroll Bar Type Constants
		vScrollBar	= SB_VERT,
		hScrollBar	= SB_HORZ
	};
 // Standard Operations
	ScrollBar1 ();
		//! replaces self
		//! ensures: self = (false, vScrollBar, 0, 0, 0, 1, 1, 1, 1)
	~ScrollBar1 ();
	void clear (void);
		//! clears self
	void transferFrom(ScrollBar1& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source 

	void attach (HWND parentWindowHandle, Integer scrollBarType);
		//!   updates self
		//!   restores parentWindowHandle, scrollBarType
		//!   requires: !self.attached  and  
		//!            ((scrollBarType == vScrollBar) or 
		//!             (scrollBarType == hScrollBar))  and
		//!            parentWindow has scrollBarType 
		//!   ensures: self.attached  and  self.scrollTypeValue = scrollBarType

	Boolean isAttached (void);
		//!   restores self
		//!   ensures:  result = self.attached

	void setRange (Integer min, Integer max);
		//!   updates self
		//!   restores min, max
		//!   requires: self.attached  and  0 <= min <= max
		//!   ensures: self.scrollMinValue = min  and  self.scrollMaxValue = max  and
		//!           self.currentPosition = min

	void setScrollPosition (Integer position);
		//!   updates self
		//!   restores position
		//!   requires: self.attached  and  self.scrollMinValue <= position <= self.scrollMaxValue
		//!   ensures: self.currentPosition = position

	void setUnits (Integer line, Integer page);
		//!   updates self
		//!   restores line, page
		//!   requires: self.attached  and  1 <= line  and  0 <= page
		//!   ensures: self.numLinesPerLineScroll = line  and  self.numLinesPerPageScroll = page

	void setWindowHeight (Integer height);
		//!   updates self
		//!   restores height
		//!   requires: self.attached  and  height >= 0  and  height is in screen units
		//!   ensures: self.windowHeightInScreenUnits = height  and
		//!         self.numLinesPerPageScroll = self.windowHeightInScreenUnits / self.lineHeightInScreenUnits

	void setLineHeight (Integer height);
		//!   updates self
		//!   restores height
		//!   requires: self.attached  and  height > 0  and  height is in screen units
		//!   ensures: self.lineHeightInScreenUnits = height  and
		//!         self.numLinesPerPageScroll = self.windowHeightInScreenUnits / self.lineHeightInScreenUnits

	Integer scrollType (void);
		//!   restores self
		//!   requires: self.attached
		//!   ensures:  result = self.scrollTypeValue

	Integer scrollMin (void);
		//!   restores self
		//!   requires: self.attached
		//!   ensures:  result = self.scrollMinValue

	Integer scrollMax (void);
		//!   restores self
		//!   requires: self.attached
		//!   ensures:  result = self.scrollMaxValue

	Integer scrollPosition (void);
		//!   restores self
		//!   requires: self.attached
		//!   ensures:  result = self.currentPosition

	Integer linesPerLineScroll (void);
		//!   restores self
		//!   requires: self.attached
		//!   ensures:  result = self.numLinesPerLineScroll

	Integer linesPerPageScroll (void);
		//!   restores self
		//!   requires: self.attached
		//!   ensures:  result = self.numLinesPerPageScroll

	Integer lineHeight (void);
		//!   restores self
		//!   requires: self.attached
		//!   ensures:  result = self.lineHeightInScreenUnits
	Integer windowHeight (void);
		//!   restores self
		//!   requires: self.attached
		//!   ensures:  result = self.windowHeightInScreenUnits

	Boolean isScrollBarEvent (WPARAM wParam);
		//!   restores self, wParam
		//!   ensures:  result = true  iff
		//!          LOWORD(wParam) member of {SB_LINEUP, SB_LINEDOWN, SB_PAGEUP, 
		//!          SB_PAGEDOWN, SB_THUMBPOSITION, SB_THUMBTRACK, SB_TOP, SB_BOTTOM,
        //!          SB_ENDSCROLL}

	Boolean isKeyStrokeScrollEvent(WPARAM wParam);
	//!   restores self, wParam
	//!   ensures:  result = true  iff
	//!      wParam member of {VK_UP, VK_DOWN, VK_PRIOR, VK_NEXT}

	void handleScrollBarEvent (WPARAM wParam);
        //!  updates self
        //!  restores wParam
        //!  requires: self.attached and
        //!        LOWORD (wParam) member of {SB_LINEUP, SB_LINEDOWN, SB_PAGEUP,
        //!        SB_PAGEDOWN, SB_THUMBPOSITION, SB_THUMBTRACK, SB_TOP, SB_BOTTOM,
        //!        SB_ENDSCROLL}
        //!   ensures:
        //!      (LOWORD (wParam) = SB_LINEUP) implies
        //!      self.currentPosition = max (self.scrollMinValue, self.currentPosition - self.numLinesPerLineScroll)
        //!      and
        //!      (LOWORD (wParam) = SB_LINEDOWN) implies
        //!      self.currentPosition = min (self.scrollMaxValue, self.currentPosition + self.numLinesPerLineScroll)
        //!      and
        //!      (LOWORD (wParam) = SB_PAGEUP) implies
        //!      self.currentPosition = max (self.scrollMinValue, self.currentPosition - self.numLinesPerPageScroll)
        //!      and
        //!      (LOWORD (wParam) = SB_PAGEDOWN) implies
        //!      self.currentPosition = min (self.scrollMaxValue, self.currentPosition + self.numLinesPerPageScroll)
        //!      and
        //!      (LOWORD (wParam) = SB_TOP) implies  self.currentPosition = self.scrollMinValue
        //!      and
        //!      (LOWORD (wParam) = SB_BOTTOM) implies  self.currentPosition = self.scrollMaxValue
        //!      and
        //!      ((LOWORD (wParam) = SB_THUMBPOSITION) || (LOWORD (wParam) = SB_THUMBTRACK)) implies
        //!      self.currentPosition = HIWORD (wParam)
	void handleMouseWheelScrollEvent(WPARAM wParam);
		//!  updates self
		//!  restores wParam
		//!  requires: self.attached 
		//!   ensures:
        //!      (GET_WHEEL_DELTA_WPARAM(wParam) > 0) implies
        //!      self.currentPosition = max (self.scrollMinValue, self.currentPosition - self.numLinesPerLineScroll)
        //!      (GET_WHEEL_DELTA_WPARAM(wParam) <= 0) implies
        //!      self.currentPosition = min (self.scrollMaxValue, self.currentPosition + self.numLinesPerLineScroll)
	void handleKeyStrokeScrollEvent(WPARAM wParam);
		//!  updates self
		//!  restores wParam
		//!  requires: self.attached and wParam member of {VK_UP, VK_DOWN, VK_PRIOR, VK_NEXT}
		//!   ensures:
        //!      (wParam = VK_UP) implies
        //!      self.currentPosition = max (self.scrollMinValue, self.currentPosition - self.numLinesPerLineScroll)
        //!      and
        //!      (wParam = VK_DOWN) implies
        //!      self.currentPosition = min (self.scrollMaxValue, self.currentPosition + self.numLinesPerLineScroll)
        //!      and
        //!      (wParam = VK_PRIOR) implies
        //!      self.currentPosition = max (self.scrollMinValue, self.currentPosition - self.numLinesPerPageScroll)
        //!      and
        //!      (wParam = VK_NEXT) implies
        //!      self.currentPosition = min (self.scrollMaxValue, self.currentPosition + self.numLinesPerPageScroll)


private: // Representation
	HWND parentWindow;
	SCROLLINFO scrollInfo;
	Integer scrollTypeValue;
	Integer scrollMinValue;
	Integer scrollMaxValue;
	Integer currentPosition;
	Integer numLinesPerLineScroll;
	Integer numLinesPerPageScroll;

	// lineHeightInScreenUnits and windowHeightInScreenUnits must be in screen units
	Integer lineHeightInScreenUnits;
	Integer windowHeightInScreenUnits;

private: // Local Operations
	void calculateLinesPerPage (void);
		//! updates: self
		//! requires: self.lineHeightInScreenUnits > 0
		//! ensures: self.numLinesPerPageScroll = self.windowHeightInScreenUnits / self.lineHeightInScreenUnits

	void ScrollBar1::executeScroll(Integer deltaScroll);
		//! updates: self
		//! ensures: window scrolled by deltaScroll

	// Disallowed ScrollBar1 Operations
	ScrollBar1& operator = (const ScrollBar1& rhs);
	ScrollBar1 (const ScrollBar1& s);
	ScrollBar1* operator & (void) {return (this);};
	const ScrollBar1* operator & (void) const {return (this);};
};



//-----------------------------------------------------------------------
// Local Operations
//-----------------------------------------------------------------------

void ScrollBar1::calculateLinesPerPage (void)
{
	numLinesPerPageScroll = windowHeightInScreenUnits / lineHeightInScreenUnits;

	if ((windowHeightInScreenUnits % lineHeightInScreenUnits) == 0) {
		// If windowHeightInScreenUnits is an exact multiple of lineHeightInScreenUnits,
		// reduce numLinesPerPageScroll by one so user will see
		// see bottom line become the top line on a page down and
		// see top line become bottom line on a page up.
		// That way user knows they didn't miss seeing any lines when
		// when paging through a document.
		numLinesPerPageScroll--;
	} // end if
	if (numLinesPerPageScroll <= 0) {
		numLinesPerPageScroll = 1;
	}
	scrollInfo.fMask = SIF_PAGE;
	scrollInfo.nPage = numLinesPerPageScroll;
	SetScrollInfo  (parentWindow, scrollTypeValue, &scrollInfo, true);
}	// calculateLinesPerPage

	//-----------------------------------------------------------------------


void ScrollBar1::executeScroll(Integer deltaScroll)
{
	if (deltaScroll != 0) {
		currentPosition += deltaScroll;
		if (scrollTypeValue == vScrollBar) {
			ScrollWindow(parentWindow, 0, -lineHeightInScreenUnits * deltaScroll, NULL, NULL);
		}
		else {
			// scrollTypeValue == hScrollBar
			ScrollWindow(parentWindow, -lineHeightInScreenUnits * deltaScroll, 0, NULL, NULL);
		} // end if
		scrollInfo.fMask = SIF_POS;
		scrollInfo.nPos = currentPosition;
		SetScrollInfo(parentWindow, scrollTypeValue, &scrollInfo, TRUE);
	} // end if
}	// executeScroll

//-----------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------

ScrollBar1::ScrollBar1 ()
{
	parentWindow = NULL;
	scrollInfo.cbSize = sizeof (SCROLLINFO);
	scrollTypeValue = vScrollBar;
	numLinesPerLineScroll = 1;
	numLinesPerPageScroll = 1;
	lineHeightInScreenUnits = 1;
	windowHeightInScreenUnits = 1;
}	// ScrollBar1

//-----------------------------------------------------------------------

ScrollBar1::~ScrollBar1 ()
{
}	// ~ScrollBar1

//-----------------------------------------------------------------------

void ScrollBar1::transferFrom(ScrollBar1& source)
{
	SCROLLINFO newScrollInfo;

	parentWindow = source.parentWindow;
	source.parentWindow = NULL;

	scrollInfo = source.scrollInfo;
	
	newScrollInfo.cbSize = sizeof(SCROLLINFO);
	source.scrollInfo = newScrollInfo;


	scrollTypeValue.transferFrom(source.scrollTypeValue);
	scrollMinValue.transferFrom(source.scrollMinValue);
	scrollMaxValue.transferFrom(source.scrollMaxValue);
	currentPosition.transferFrom(source.currentPosition);
	numLinesPerLineScroll.transferFrom(source.numLinesPerLineScroll);
	numLinesPerPageScroll.transferFrom(source.numLinesPerPageScroll);

	// lineHeightInScreenUnits and windowHeightInScreenUnits must be in screen units
	lineHeightInScreenUnits.transferFrom(source.lineHeightInScreenUnits);
	windowHeightInScreenUnits.transferFrom(source.windowHeightInScreenUnits);

	source.clear();
}	// transferFrom

//-----------------------------------------------------------------------

void ScrollBar1::clear (void)
{
	scrollTypeValue = vScrollBar;
	scrollMinValue = 0;
	scrollMaxValue = 0;
	currentPosition = 0;
	numLinesPerLineScroll = 1;
	numLinesPerPageScroll = 1;
	lineHeightInScreenUnits = 1;
	windowHeightInScreenUnits = 1;
	parentWindow = NULL;

	scrollInfo.fMask = SIF_RANGE | SIF_POS;
	scrollInfo.nMin = scrollMinValue;
	scrollInfo.nMax = scrollMaxValue;
	scrollInfo.nPos = currentPosition;
	SetScrollInfo  (parentWindow, scrollTypeValue, &scrollInfo, FALSE);
}	// clear

//-----------------------------------------------------------------------

void ScrollBar1::attach (HWND parentWindowHandle, Integer scrollBarType)
{
	parentWindow = parentWindowHandle;
	scrollTypeValue = scrollBarType;
}	// attach

//-----------------------------------------------------------------------

void ScrollBar1::setRange (Integer min, Integer max)
{
	scrollMinValue = min;
	scrollMaxValue = max;

	if ((currentPosition < min) || (currentPosition > max)) {
		currentPosition = min;
	} // end if

	scrollInfo.fMask = SIF_RANGE | SIF_POS;
	scrollInfo.nMin = scrollMinValue;
	scrollInfo.nMax = scrollMaxValue;
	scrollInfo.nPos = currentPosition;
	SetScrollInfo  (parentWindow, scrollTypeValue, &scrollInfo, TRUE);		
}	// setRange

//-----------------------------------------------------------------------

void ScrollBar1::setUnits (Integer line, Integer page)
{
	numLinesPerLineScroll = line;
	numLinesPerPageScroll = page;
}	// setUnits

//-----------------------------------------------------------------------

void ScrollBar1::setWindowHeight (Integer height)
{
	windowHeightInScreenUnits = height;
	calculateLinesPerPage ();
	if (scrollMaxValue <= numLinesPerPageScroll) {
		// If user adjusted window size that makes the number of lines in the entire window
		// less than 1 window's worth of lines, then make sure first line is back at the top of the
		// window
		currentPosition = scrollMinValue;
		scrollInfo.fMask = SIF_POS;
		scrollInfo.nPos = currentPosition;
		SetScrollInfo  (parentWindow, scrollTypeValue, &scrollInfo, TRUE);
	} // end if
}	// setWindowHeight

//-----------------------------------------------------------------------

void ScrollBar1::setLineHeight (Integer height)
{
	lineHeightInScreenUnits = height;
	calculateLinesPerPage ();
}	// setLineHeight

//-----------------------------------------------------------------------

void ScrollBar1::setScrollPosition (Integer position)
{
	scrollInfo.fMask = SIF_POS;
	scrollInfo.nPos = position;
	SetScrollInfo  (parentWindow, scrollTypeValue, &scrollInfo, TRUE);
	currentPosition = position;
}	// setScrollPosition

//-----------------------------------------------------------------------

Boolean ScrollBar1::isAttached (void)
{
	return parentWindow != NULL;
} // isAttached

//-----------------------------------------------------------------------

Integer ScrollBar1::scrollType (void)
{
	return scrollTypeValue;
} // scrollType

//-----------------------------------------------------------------------

Integer ScrollBar1::scrollMin (void)
{
	return scrollMinValue;
} // scrollMin

//-----------------------------------------------------------------------

Integer ScrollBar1::scrollMax (void)
{
	return scrollMaxValue;
} // scrollMax

//-----------------------------------------------------------------------

Integer ScrollBar1::scrollPosition (void)
{
	return currentPosition;
} // scrollPosition

//-----------------------------------------------------------------------

Integer ScrollBar1::linesPerLineScroll (void)
{
	return numLinesPerLineScroll;
} // linesPerLineScroll

//-----------------------------------------------------------------------

Integer ScrollBar1::linesPerPageScroll (void)
{
	return numLinesPerPageScroll;
} // linesPerPageScroll

//-----------------------------------------------------------------------

Integer ScrollBar1::lineHeight (void)
{
	return lineHeightInScreenUnits;
} // lineHeight

//-----------------------------------------------------------------------

Integer ScrollBar1::windowHeight (void)
{
	return windowHeightInScreenUnits;
} // windowHeight

//-----------------------------------------------------------------------

Boolean ScrollBar1::isScrollBarEvent (WPARAM wParam)
{
	Boolean isScrollEvent;

	switch (LOWORD (wParam)) {
		case SB_LINEUP:
		case SB_LINEDOWN:
		case SB_PAGEUP:
		case SB_PAGEDOWN:
		case SB_THUMBPOSITION:
		case SB_THUMBTRACK:
		case SB_TOP:
		case SB_BOTTOM:
		case SB_ENDSCROLL:
			isScrollEvent = true;
			break;
		default:
			break;
	} // end switch
	return isScrollEvent;
} // isScrollBarEvent

Boolean ScrollBar1::isKeyStrokeScrollEvent(WPARAM wParam)
{
	Boolean isScrollEvent;

	switch (wParam) {
	case VK_UP:
	case VK_DOWN:
	case VK_PRIOR:
	case VK_NEXT:
		isScrollEvent = true;
		break;
	default:
		break;
	} // end switch

	return isScrollEvent;
} // isKeyStrokeScrollEvent

//-----------------------------------------------------------------------

void ScrollBar1::handleScrollBarEvent (WPARAM wParam)
{
	Integer deltaScroll;

	switch (LOWORD (wParam)) {
		case SB_LINEUP:
			if (currentPosition > scrollMinValue) {
				deltaScroll = -numLinesPerLineScroll;
			} // end if
			break;
		case SB_LINEDOWN:
			if (currentPosition < scrollMaxValue) {
				deltaScroll = numLinesPerLineScroll;
			} // end if
			break;
		case SB_PAGEUP:
			if ((currentPosition - numLinesPerPageScroll) >= scrollMinValue) {
				deltaScroll = -numLinesPerPageScroll;
			} else {
				deltaScroll = -currentPosition;
			} // end if
			break;
		case SB_PAGEDOWN:
			if ((currentPosition + numLinesPerPageScroll) <= scrollMaxValue) {
				deltaScroll = numLinesPerPageScroll;
			} else {
				deltaScroll = (scrollMaxValue - currentPosition);
			} // end if
			break;
		case SB_THUMBPOSITION:
			deltaScroll = (HIWORD (wParam) - currentPosition);
			break;
		case SB_THUMBTRACK:
			deltaScroll = (HIWORD (wParam) - currentPosition);
			break;
		default:
			break;
	} // end switch
	executeScroll(deltaScroll);
}	// handleScrollBarEvent

	//-----------------------------------------------------------------------


void ScrollBar1::handleMouseWheelScrollEvent(WPARAM wParam)
{
	Integer deltaScroll;

	if (GET_WHEEL_DELTA_WPARAM(wParam) > 0) {
		// SB_LINEUP
		if (currentPosition > scrollMinValue) {
			deltaScroll = -numLinesPerLineScroll;
		} // end if
	}
	else {
		// SB_LINEDOWN
		if (currentPosition < scrollMaxValue) {
			deltaScroll = numLinesPerLineScroll;
		} // end if
	} // end if
	executeScroll(deltaScroll);
} // handleMouseWheelScrollEvent

  //-----------------------------------------------------------------------

void ScrollBar1::handleKeyStrokeScrollEvent(WPARAM wParam)
{
	Integer deltaScroll;

	switch (wParam) {
	case VK_UP:
		// SB_LINEUP
		if (currentPosition > scrollMinValue) {
			deltaScroll = -numLinesPerLineScroll;
		} // end if
		break;
	case VK_DOWN:
		// SB_LINEDOWN
		if (currentPosition < scrollMaxValue) {
			deltaScroll = numLinesPerLineScroll;
		} // end if
		break;
	case VK_PRIOR:
		// SB_PAGEUP
			if ((currentPosition - numLinesPerPageScroll) >= scrollMinValue) {
				deltaScroll = -numLinesPerPageScroll;
			}
			else {
				deltaScroll = -currentPosition;
			} // end if
		break;
	case VK_NEXT:
		// SB_PAGEDOWN
			if ((currentPosition + numLinesPerPageScroll) <= scrollMaxValue) {
				deltaScroll = numLinesPerPageScroll;
			}
			else {
				deltaScroll = (scrollMaxValue - currentPosition);
			} // end if
		break;
	default:
		break;
	} // end switch
	executeScroll(deltaScroll);
} // handleKeyStrokeScrollEvent

