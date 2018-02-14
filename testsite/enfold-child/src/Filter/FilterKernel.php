<?php
namespace LouisvilleGeek\EnfoldChild\Filter;

use LouisvilleGeek\EnfoldChild\Filter\Filter;
use LouisvilleGeek\EnfoldChild\Filter\Hooks\PageName;
use LouisvilleGeek\EnfoldChild\Filter\Hooks\ParentPageName;
use ObjectiveWP\Framework\Filter\FilterHook;
use ObjectiveWP\Framework\Filter\FilterKernel as BaseFilterKernel;

/**
 * Class FilterLoader Loads filters
 *
 * @package LouisvilleGeek\EnfoldChild\Loaders
 */
class FilterKernel extends BaseFilterKernel
{

    /**
     * The filters to load
     *
     * @return FilterHook[]
     */
    public function filters()
    {
        return [
            PageName::class,
            ParentPageName::class
        ];
    }

}