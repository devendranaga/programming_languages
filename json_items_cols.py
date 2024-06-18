import json

with open("json.json") as json_data:
        d = json.load(json_data)

        rule_id_list = []
        event_types = []

        for i in d:
                rule_id_list.append(i['rule_id'])
                event_types.append(i['event_type'])

        print(rule_id_list, event_types)
