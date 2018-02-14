import * as React from "react";

interface HelloWorldProps {
 name?: string;
}

export class HelloWorld extends React.Component<HelloWorldProps> {
    render() {
        return (
            <h1>Hello {this.props.name}!</h1>
        );
    }
}