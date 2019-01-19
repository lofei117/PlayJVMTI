package info.lofei.demo.jvmti;

import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;

public class Controller {

    public TextField tfInput;

    public Label lbText;

    public void setText(MouseEvent mouseEvent) {
        System.out.println("Set text.");
        lbText.setText(tfInput.getText());
        setBreakpoint();
    }

    public void setBreakpoint() {
        System.out.println("Set breakpoint call.");
    }
}
