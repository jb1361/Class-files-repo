#pragma once
/*
	Checking Version for ScrollBar
	Author: Dr. Holly
*/


template <class ScrollBarUnchecked>
class ScrollBarChecking1:
	public ScrollBarUnchecked
{
public:

void attach (HWND parent_window, Integer scrollBarType)
{
	Text operationName ("attach");

	assertDetached (operationName);
	if ((scrollBarType != ScrollBarUnchecked::vScrollBar) &&
		(scrollBarType != ScrollBarUnchecked::hScrollBar)) {
		OutputDebugString (L"Operation: attach\n");
		OutputDebugString (L"Assertion Failed:\n");
		OutputDebugString (L"\tscrollBarType == vScrollBar  or\n");
		OutputDebugString (L"\tscrollBarType == hScrollBar\n");
		DebugBreak ();
	}	// end if 
	ScrollBarUnchecked::attach (parent_window, scrollBarType);
}	// attach

//-------------------------------------------------------------------

void setRange (Integer min, Integer max)
{
	Text operationName ("setRange");

	assertAttached (operationName);
	if ((min < 0) || (max < min)) {
		OutputDebugString (L"Operation: setRange\n");
		OutputDebugString (L"Assertion failed: 0 <= min <= max\n");
		DebugBreak ();
	}	// end if 
	ScrollBarUnchecked::setRange (min, max);
}	// setRange

//-------------------------------------------------------------------

void setScrollPosition (Integer position)
{
	Text operationName ("setScrollPosition");

	assertAttached (operationName);
	if ((position < ScrollBarUnchecked::scrollMin ()) ||
		(position > ScrollBarUnchecked::scrollMax ())) {
		OutputDebugString (L"Operation: setScrollPosition\n");
		OutputDebugString (L"Assertion failed: self.scroll_min <= position <= self.scroll_max\n");
		DebugBreak ();
	}	// end if 
	ScrollBarUnchecked::setScrollPosition (position);
}	// setScrollPosition

//-------------------------------------------------------------------

void setUnits (Integer line, Integer page)
{
	Text operationName ("setUnits");

	assertAttached (operationName);
	if ((line < 1) || (page < 0)) {
		OutputDebugString (L"Operation: setUnits\n");
		OutputDebugString (L"Assertion failed: 1 <= line  and  0 <= page\n");
		DebugBreak ();
	}	// end if 
	ScrollBarUnchecked::setUnits (line, page);
}	// setUnits

//-------------------------------------------------------------------

void setWindowHeight (Integer height)
{
	Text operationName ("setWindowHeight");

	assertAttached (operationName);
	if (height < 0) {
		OutputDebugString (L"Operation: setWindowHeight\n");
		OutputDebugString (L"Assertion failed: height >= 0\n");
		DebugBreak ();
	}	// end if 
	ScrollBarUnchecked::setWindowHeight (height);
}	// setWindowHeight

//-------------------------------------------------------------------

void setLineHeight (Integer height)
{
	Text operationName ("setLineHeight");

	assertAttached (operationName);
	if (height <= 0) {
		OutputDebugString (L"Operation: setLineHeight\n");
		OutputDebugString (L"Assertion failed: height > 0\n");
		DebugBreak ();
	}	// end if 
	ScrollBarUnchecked::setLineHeight (height);
}	// setLineHeight

//-------------------------------------------------------------------

Integer scrollType (void)
{
	Text operationName ("scrollType");

	assertAttached (operationName);
	return ScrollBarUnchecked::scrollType ();
}	// scrollType

//-------------------------------------------------------------------

Integer scrollMin (void)
{
	Text operationName ("scrollMin");

	assertAttached (operationName);
	return ScrollBarUnchecked::scrollMin ();
}	// scrollMin

//-------------------------------------------------------------------

Integer scrollMax (void)
{
	Text operationName ("scrollMax");

	assertAttached (operationName);
	return ScrollBarUnchecked::scrollMax ();
}	// scrollMin

//-------------------------------------------------------------------

Integer scrollPosition (void)
{
	Text operationName ("scrollPosition");

	assertAttached (operationName);
	return ScrollBarUnchecked::scrollPosition ();
}	// scrollMin

//-------------------------------------------------------------------

Integer linesPerLineScroll (void)
{
	Text operationName ("linesPerLineScroll");

	assertAttached (operationName);
	return ScrollBarUnchecked::linesPerLineScroll ();
}	// linesPerLineScroll

//-------------------------------------------------------------------

Integer linesPerPageScroll (void)
{
	Text operationName ("linesPerPageScroll");

	assertAttached (operationName);
	return ScrollBarUnchecked::linesPerPageScroll ();
}	// linesPerPageScroll

//-------------------------------------------------------------------

Integer lineHeight (void)
{
	Text operationName ("lineHeight");

	assertAttached (operationName);
	return ScrollBarUnchecked::lineHeight ();
}	// lineHeight

//-------------------------------------------------------------------

Integer windowHeight (void)
{
	Text operationName ("windowHeight");

	assertAttached (operationName);
	return ScrollBarUnchecked::windowHeight ();
}	// windowHeight

//-------------------------------------------------------------------

void handleScrollBarEvent (WPARAM wParam)
{
	Text operationName ("handleScrollBarEvent");

	assertAttached (operationName);
	if (!ScrollBarUnchecked::isScrollBarEvent(wParam)) {
		OutputDebugString (L"Operation: handleScrollBarEvent\n");
		OutputDebugString (L"Assertion failed: isScrollBarEvent(wParam)\n");
		DebugBreak ();
	}	// end if 
	ScrollBarUnchecked::handleScrollBarEvent (wParam);
}	// handleScrollBarEvent

//-------------------------------------------------------------------

void handleMouseWheelScrollEvent(WPARAM wParam)
{
	Text operationName("handleMouseWheelScrollEvent");

	ScrollBarUnchecked::handleMouseWheelScrollEvent(wParam);
}	// handleMouseWheelScrollEvent


//-------------------------------------------------------------------

void handleKeyStrokeScrollEvent(WPARAM wParam)
{
	Text operationName("handleKeyStrokeScrollEvent");

	assertAttached(operationName);
	if (!ScrollBarUnchecked::isKeyStrokeScrollEvent(wParam)) {
		OutputDebugString(L"Operation: handleKeyStrokeScrollEvent\n");
		OutputDebugString(L"Assertion failed: isKeyStrokeScrollEvent(wParam)\n");
		DebugBreak();
	}	// end if 
	ScrollBarUnchecked::handleKeyStrokeScrollEvent(wParam);
}	// handleKeyStrokeScrollEvent

//-------------------------------------------------------------------

private:

inline void assertAttached (Text& operationName)
{
	// Assert that ScrollBar is attached
	// If it's not Attached, then output error message 
	// and transfer control to debugger.
	if (!ScrollBarUnchecked::isAttached ()) {
		Text outputString ("Operation: ");

		outputString.append (operationName);
		OutputDebugString (outputString);
		OutputDebugString (L"\n");
		OutputDebugString (L"Assertion Failed: is attached\n");
		DebugBreak ();
	}	// end if 
}	// assertAttached

//-------------------------------------------------------------------

inline void assertDetached (Text& operationName)
{
	// Assert that ScrollBar is not attached
	// If it is Attached, then output error message 
	// and transfer control to debugger.
	if (ScrollBarUnchecked::isAttached ()) {
		Text outputString ("Operation: ");

		outputString.append (operationName);
		OutputDebugString (outputString);
		OutputDebugString (L"\n");
		OutputDebugString (L"Assertion Failed: not attached\n");
		DebugBreak ();
	}	// end if 
}	// assertDetached

};
