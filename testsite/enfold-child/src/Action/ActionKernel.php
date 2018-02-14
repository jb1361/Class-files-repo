<?php
namespace LouisvilleGeek\EnfoldChild\Action;

use ObjectiveWP\Framework\Action\ActionHook;
use ObjectiveWP\Framework\Action\ActionKernel as ActionKernelBase;

/**
 * Class ActionLoader
 * Loads Action
 *
 * @package LouisvilleGeek\EnfoldChild\Loaders
 */
class ActionKernel extends ActionKernelBase
{

    /**
     * The actions to load
     *
     * @return ActionHook[]
     */
    protected function actions(): array
    {
        return [
            // add actions here
        ];
    }

}