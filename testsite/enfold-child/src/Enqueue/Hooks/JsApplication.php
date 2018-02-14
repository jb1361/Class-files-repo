<?php
namespace LouisvilleGeek\EnfoldChild\Enqueue\Hooks;

use ObjectiveWP\Framework\Contracts\Foundation\Application;
use ObjectiveWP\Framework\Enqueue\EnqueueHook;

/**
 * Class EnqueueLoader
 * Loads the webpack build
 *
 * @package LouisvilleGeek\EnfoldChild\Loaders
 */
class JsApplication extends EnqueueHook
{
    protected $app;

    /**
     * JsApplication constructor.
     * @param Application $app
     */
    public function __construct(Application $app) {
        $this->app = $app;
    }

    /**
     * Enqueue scripts or styles.
     *
     * @param array ...$args The arguments passed
     * @return void
     */
    public function handle(...$args)
    {
        $this->enqueueScript('react', $this->app->getFileUri('assets/bower_components/react/react.js'), [], $this->app->getVersion());
        $this->enqueueScript('react-dom', $this->app->getFileUri('assets/bower_components/react/react-dom.js'), [], $this->app->getVersion());
        $this->enqueueScript($this->app->prefix('application'), $this->app->getFileUri('assets/ts/dist/app.bundle.js'), ['jquery', 'react', 'react-dom'], $this->app->getVersion());
    }
}