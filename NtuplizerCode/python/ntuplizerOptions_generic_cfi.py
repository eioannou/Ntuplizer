import FWCore.ParameterSet.Config as cms

config = dict()

config["RUNONMC"] = True

config["USEJSON"] = not (config["RUNONMC"])
config["JSONFILE"] = "Cert_314472-325175_13TeV_PromptReco_Collisions18_JSON.txt "

config["DOMISSINGET"] = True
