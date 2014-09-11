<?php
mb_internal_encoding("utf-8");
/************************************************************************************************/
/* Author: Ozgur Vatansever                                                                     */
/* Email: ozgurvt@gmail.com                                                                     */
/* This library provides a pure PHP interface for the EST SanalPOS API.                         */
/* Feel free to report bugs, contribute, use in your open source projects without permission.   */
/************************************************************************************************/

class XMLBuilder extends DOMDocument {
  /***********************************************************************************/
  /* This class wrapps around the DOMDocument class which is inside the xml library, */
  /* and provides some utility functions to build up XML document easily.            */
  /***********************************************************************************/
  public $rootElement;

  public function __construct($tag = "CC5Request") {
    /************************************************************************************/
    /* This class wrapps around the Document class which is inside the minidom library, */
    /* and provides some utility functions to build up XML document easily.             */
    /************************************************************************************/
    parent::__construct("1.0");
    $element = $this->createElement($tag);
    $this->rootElement = $element;
    $this->appendChild($this->rootElement);
  }

  public function root() {
    /* Gets the root element which is at the top of Dom hierarchy. */
    return $this->rootElement;
  }

  public function createElementWithTextNode($tagName, $nodeValue) {
    /**********************************************************************/
    /* Creates a dom element with the given tag name and the node value.  */
    /* @input: string, string                                             */
    /* @output: DOM Element                                               */
    /**********************************************************************/
    if($nodeValue == null) {
      $nodeValue = "";
    }
    $element = $this->createElement(strval($tagName));
    $node = $this->createTextNode(strval($nodeValue));
    $element->appendChild($node);
    return $element;
  }

  public function createElementsWithTextNodes($arguments) {
    /********************************************************************************/
    /* Creates a list of DOM Element instances with the given unlimited parameters. */
    /* @input: string, string ...                                                   */
    /* @output: [DOM Element, DOM Element, ...]                                     */
    /********************************************************************************/
    $resultArray = array();
    foreach($arguments as $k => $v) {
      array_push($resultArray, $this->createElementWithTextNode($k, $v));
    }
    return $resultArray;
  }

  public function appendListOfElementsToElement($element, $elements) {
    /* Appends list of DOM elements to the given DOM element. */
    foreach($elements as $ele) {
      $element->appendChild($ele);
    }
  }

  public function __toString() {
    return $this->saveXML();
  }

  public static function get_data($xmlObj, $tag) {
    $elements = $xmlObj->getElementsByTagName($tag);
    if($elements->length > 0) {
      $item = $elements->item(0);
      $childiren = $item->childNodes;
      if($childiren->length > 0) {
        return $childiren->item(0)->nodeValue;
      }
      return "";
    }
    return "";
  }

}

?>