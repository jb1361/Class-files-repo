<?php

namespace LouisvilleGeek\EnfoldChild;

use LouisvilleGeek\EnfoldChild\Action\ActionKernel;
use LouisvilleGeek\EnfoldChild\Filter\FilterKernel;
use LouisvilleGeek\EnfoldChild\Enqueue\EnqueueKernel;
use LouisvilleGeek\EnfoldChild\ShortCode\ShortCodeKernel;
use ObjectiveWP\Framework\Contracts\Kernel;
use ObjectiveWP\Framework\Foundation\Application as BaseApplication;
/**
 * Class Application
 * @package LouisvilleGeek\EnfoldChild
 * @see https://codex.wordpress.org/Plugin_API/Action_Reference when "setup_theme" is called in wordpress
 */
class Application extends BaseApplication
{

    /**
     * A list of the kernels to bootstrap
     * @return Kernel[]
     */
    protected function kernels()
    {
        return [
            EnqueueKernel::class,
            ShortCodeKernel::class,
            FilterKernel::class,
            ActionKernel::class
        ];
    }

    public function bootstrap()
    {
        /**
         * Added class section Enfold Avia builder..
         */
        add_theme_support('avia_template_builder_custom_css');
        parent::bootstrap();
    }
}